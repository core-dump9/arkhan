def reverse(word)
	word = word.reverse
return word
end

def isprimefast(n)
	t = [];
	for i in 1..10 do
		if n%i == 0 then
			t << i
		end
	end

	if n < 2 then
		return false;
	elsif t.length == 2 or t.length == 1
		return true;
	else
		return false;
	end	
end