local elements = {}

Vec2 = {
	x = 0,
	y = 0
}

function Vec2:new()
	local v = setmetatable({}, {__index = Vec2})

	return v
end

function Vec2:add(a, b)
	print(a, b)
end

function Vec2:sub(a, b)

end

UIElement = {
	pos = nil
	bounds = nil
}

function UIElement:new()
	local element = setmetatable({}, {__index = UIElement})

	element.pos = Vec2:new()
	element.bounds = Vec2:new()

	return element
end
