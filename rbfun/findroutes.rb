def findroutes(number)
	if (number == 1) then
		return 2;
	else
		return number*findroutes(number-1) + 2;
	end
end

number = gets().to_i

answer = findroutes(number)

puts answer;
