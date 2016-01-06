--
-- Author: zyuq
-- Date: 2015-12-25 15:09:29
--
local RockerLayer=class("RockerLayer", function ()
	return display.newNode()
end)


tagDirection = {
	rocker_STARY=0,
    rocker_RIGHT=1,
    rocker_UP=2,
    rocker_LEFT=3,
    rocker_DOWN=4,
    rocker_LEFT_UP=5,
    rocker_LEFT_DOWN=6,
    rocker_RIGHT_UP=7,
    rocker_RIGHT_DOWN=8
}

function RockerLayer:ctor()
	self:initRocker()
end

function RockerLayer:initRocker( )
	--背景图
	local bg = display.newSprite("zhucheng.png")
	bg:pos(display.cx, display.cy)
	bg:addTo(self)
    --摇杆背景图
	self.RockerBG=display.newSprite("caogan-waiyuan.png")
	self.RockerBG:pos(self:getPositionX() + display.left + self.RockerBG:getContentSize().width/2 +30,
		self:getPositionY()+ display.bottom + self.RockerBG:getContentSize().width/2 + 30)
	self.RockerBG:addTo(self)
    --摇杆
	self.Rocker = display.newSprite("caozuodian1.png")
	:pos(self.RockerBG:getPosition())
	:addTo(self)
    --摇杆位置的，quick中是一个表 表示点，进行参数的传递
	self.RockerBGPos = {}
	self.RockerBGPos.x = self.RockerBG:getPositionX()
	self.RockerBGPos.y = self.RockerBG:getPositionY()
	-- 设置半径
	self.RockerBGR = self.RockerBG:getContentSize().width/2

   --在这个函数中进行触摸事件的注册
	self:addTouch()


end
--求触屏点和摇杆位置点之间的距离
function RockerLayer:distance(p1,p2)74
	return math.sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y))
end
--触屏点和摇杆位置点之间余弦值
function RockerLayer:corea(p1,p2)--触屏点，摇杆位置
	return (p1.x - p2.x)/(self:distance(p1,p2))
end
--选择方向，传递的参数是触屏点和摇杆位置点的之间的余弦值，和触屏点
function RockerLayer:checkdirection(angle,p)
	--"第一象限"
	if (p.x >= self.RockerBGPos.x) and (p.y >= self.RockerBGPos.y) then
		--弧度转角度，quick的封装，可以在cocos中自行封装，下面是代码
		-- 		function math.radian2angle(radian)
		-- 	return radian/math.pi*180
		-- end
		if (math.radian2angle(angle)>22.5) and (math.radian2angle(angle)<67.5) then
			--向上
			-- print("右上")
			--self.move表示的移动的方向
			self.move = tagDirection.rocker_RIGHT_UP
			return
		elseif math.radian2angle(angle)>67.5 then
			-- print("上")
			self.move = tagDirection.rocker_UP
			return
		elseif math.radian2angle(angle)<22.5 then
			-- print("右")
			self.move = tagDirection.rocker_RIGHT
			return
		end
    --“第二象限”
	elseif (p.x < self.RockerBGPos.x) and (p.y > self.RockerBGPos.y) then
		if (math.radian2angle(angle)>112.5) and (math.radian2angle(angle)<157.5) then
			-- print("左上")
			self.move = tagDirection.rocker_LEFT_UP
			return
		elseif math.radian2angle(angle) < 112.5 then
			-- print("上")
			self.move = tagDirection.rocker_UP
			return
		elseif math.radian2angle(angle) > 157.5 then
			-- print("左")
			self.move = tagDirection.rocker_LEFT
			return
		end
   -- “第三象限”
	elseif (p.x < self.RockerBGPos.x) and (p.y <= self.RockerBGPos.y) then

		if (math.radian2angle(angle)>112.5) and (math.radian2angle(angle)<157.5) then
			-- print("左下")
			self.move = tagDirection.rocker_LEFT_DOWN
			return
		elseif math.radian2angle(angle)>112.5 then
			-- print("左")
			self.move = tagDirection.rocker_LEFT
			return
		elseif math.radian2angle(angle)<157.5 then
			-- print("下")
			self.move = tagDirection.rocker_DOWN
			return
		end
--“第四象限”
	elseif (p.x > self.RockerBGPos.x) and (p.y < self.RockerBGPos.y) then
		if (math.radian2angle(angle)>22.5) and (math.radian2angle(angle)<67.5) then
			-- print("右下")
			self.move = tagDirection.rocker_RIGHT_DOWN
			return
		elseif math.radian2angle(angle)>67.5 then
			-- print("下")
			self.move = tagDirection.rocker_DOWN
			return
		elseif math.radian2angle(angle)<22.5 then
			-- print("右")
			self.move = tagDirection.rocker_RIGHT
			return
		end
	end
end
function RockerLayer:addTouch()
	local function touchbegan( location,event )
	    local p=location:getLocation()
		--比半径大返回false
		if self:distance(p, self.RockerBGPos)< self.RockerBGR then
   --          if self._schedule ~= nil then
			-- 		scheduler.unscheduleGlobal(self.schedule)
			-- end
		 --   self.schedule=scheduler.scheduleGlobal(handler(self, self.update),0.1)
			return true
		end

		return false

	end

	local function touchended(location,event )
        self.move=0
        self.Rocker:setPosition(self.RockerBGPos)

  --       scheduler.unscheduleGlobal(self.schedule)
		-- self.schedule = nil
    end

    local function touchmoved( location ,event )
    	local p=location:getLocation()
    	--求两点之间的余弦值
    	angle=math.acos(self:corea(p,self.RockerBGPos))
        --选择方向，设置self.move 的值
        self:checkdirection(angle,p)

        --分两种情况，第一种情况是在圆外
    	if self:distance(p,self.RockerBGPos) > self.RockerBGR then
    		--x,y表示的两个点之间的x,y的坐标差
			local x = self.RockerBGR * math.cos(angle)
			local y = self.RockerBGR * math.sin(angle)
             --在位置上方的时候进行的+y
			if p.y >self.RockerBGPos.x then
				self.Rocker:setPosition(cc.p(self.RockerBGPos.x+x,self.RockerBGPos.y+y))
			else
				--在下方的时候是进行-y
				self.Rocker:setPosition(cc.p(self.RockerBGPos.x+x,self.RockerBGPos.y-y))
			end
	
		else
			--第二种情况是圆内
			self.Rocker:setPosition(p)
		end

    end
  -- 触摸事件
    local listener = cc.EventListenerTouchOneByOne:create()
	local dis  = cc.Director:getInstance():getEventDispatcher()
	-- listener
	listener:registerScriptHandler(touchbegan,cc.Handler.EVENT_TOUCH_BEGAN)
	listener:registerScriptHandler(touchended,cc.Handler.EVENT_TOUCH_ENDED)
	listener:registerScriptHandler(touchmoved,cc.Handler.EVENT_TOUCH_MOVED)
	dis:addEventListenerWithSceneGraphPriority(listener, self)

end
--在这个类中没有调用
function RockerLayer:update()
	--在touchmoved函数中已经进行堆move进行了赋值，先在定时器的会调函数中进行英雄动作的执行
	if self.move == tagDirection.rocker_STARY then
		print("left")
	elseif self.move == tagDirection.rocker_RIGHT then
		--向右移动
		print("right")
		
		
	elseif self.move == tagDirection.rocker_UP then
		--向上移动
		print("up")
		-- self.hero:setPosition(self.hero:getPositionX(),self.hero:getPositionY() + 10)
	elseif self.move == tagDirection.rocker_LEFT then
		--向左移动
		print("left")
	elseif self.move == tagDirection.rocker_DOWN then
		--向下移动
		print("down")
		
	elseif self.move == tagDirection.rocker_LEFT_UP then
		--向左下移动
		print("leftup")
		
		-- self.hero:setPosition(self.hero:getPositionX() - 3.5,self.hero:getPositionY() + 7)
	elseif self.move == tagDirection.rocker_LEFT_DOWN then
		--向左上移动
		
		
		-- self.hero:setPosition(self.hero:getPositionX() - 3.5,self.hero:getPositionY() - 7)
	elseif self.move == tagDirection.rocker_RIGHT_UP then
		--向右上移动
		
		
		-- self.hero:setPosition(self.hero:getPositionX() + 3.5,self.hero:getPositionY() + 7)
	elseif self.move == tagDirection.rocker_RIGHT_DOWN then
		--向右下移动
		
		
		
	end
	
end



return RockerLayer