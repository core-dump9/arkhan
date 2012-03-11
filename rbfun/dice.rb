num_ = [1, 2, 3, 4, 5, 6]
num__ = [1, 2, 3, 4, 5, 6]
n = 0
while n == n do
num_.shuffle!.shuffle!
num__.shuffle!.shuffle!
puts "you rolled a #{num_[0]},#{num__[0]}"
n+=1
if  num_[0] == 6 and num__[0] == 6
puts "roll the dice again"
n+=1
end
break if n == 1 or n == 2 
end
