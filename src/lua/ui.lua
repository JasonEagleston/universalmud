local FileAccess = require("lua/fileaccess")
local Vec2 = require("lua/vec2")

local elements = {}

UIElement = {
	pos = nil,
	bounds = nil,
	anchors = {},
	text = "",
	onclick = nil,
	onhover = nil,
	movable = 0,
	resizable = 0,
}

function UIElement:new(x, y, bx, by)
	local element = setmetatable({}, {__index = UIElement})

	element.pos = Vec2:new(x, y)
	element.bounds = Vec2:new(bx, by)

	return element
end

-- Import UI elements and load at start.


