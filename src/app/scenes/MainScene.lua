
local MainScene = class("MainScene", function()
    return display.newScene("MainScene")
end)
scheduler=require("framework.scheduler")
RockerLayer=require("app.scenes.RockerLayer")


function MainScene:ctor()
     self.rocker=require("app.scenes.RockerLayer").new()
    self:addChild(self.rocker)
    self.schedule=scheduler.scheduleGlobal(handler(self, self.update),0.1)
end
function MainScene:update()
	if self.rocker.move == tagDirection.rocker_STARY then
		print("nnnnnn")
	elseif self.rocker.move == tagDirection.rocker_RIGHT then
		--向右移动
		print("right")
		
		
	elseif self.rocker.move == tagDirection.rocker_UP then
		--向上移动
		print("up")
		-- self.hero:setPosition(self.hero:getPositionX(),self.hero:getPositionY() + 10)
	elseif self.rocker.move == tagDirection.rocker_LEFT then
		--向左移动
		print("left")
	elseif self.rocker.move == tagDirection.rocker_DOWN then
		--向下移动
		print("down")
		
	elseif self.rocker.move == tagDirection.rocker_LEFT_UP then
		--向左下移动
		print("leftup")
		
		-- self.hero:setPosition(self.hero:getPositionX() - 3.5,self.hero:getPositionY() + 7)
	elseif self.rocker.move == tagDirection.rocker_LEFT_DOWN then
		--向左上移动
		
		
		-- self.hero:setPosition(self.hero:getPositionX() - 3.5,self.hero:getPositionY() - 7)
	elseif self.rocker.move == tagDirection.rocker_RIGHT_UP then
		--向右上移动
		
		
		-- self.hero:setPosition(self.hero:getPositionX() + 3.5,self.hero:getPositionY() + 7)
	elseif self.rocker.move == tagDirection.rocker_RIGHT_DOWN then
		--向右下移动
		
		
		
	end
	
end
function MainScene:onEnter()
end

function MainScene:onExit()
	scheduler.unscheduleGlobal(self.schedule)
end

return MainScene
