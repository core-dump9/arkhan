def sexornot():
	print "welcome to the game of sex, here is an algorithm to get you laid";
	print "you have 30 minutes to convince her that having sex with you is a good idea, one she'd wanna repeat";
##here is the real deal


def nohit():
	print "forget her and move to a better girl, it's all just about sex."
	start();
	#begin();
	#chanceornot();


def chanceornot(mname, gname, time):
	points = 0;
	if(len(mname+gname) > 4):
		#begin the sex evaluation algorithm;
		
		print ("what colour is her clothing ? ");
		clothcolor = str(raw_input());
		print ("compliment her on it, say something non-tacky like it matches her eyes. only if it does!!");
		print ("did she smile ?? yes or no");
		response = str(raw_input());
		if response == "yes":
			points+=1;
			print "way to go, you have ", points, " point";
			sexornot();
		else:
			print "let's try a different approach.., is she drinking??";
			response = str(raw_input());
			if response == "yes" :
				print "offer to buy her a drink";
				print "did she accept??";
				response = str(raw_input());
				if response == "yes":
					points+=1;
					print ("now you have ", points, " point");
					sexornot();
				else:
					print ("let's try something else entirely");
					print ("are you bold enough??");
					response = str(raw_input());
					if response == "yes":
						print("tell her that you are attracted to her and you want to get to know her better if she doesn't mind");
						print("did she give an affirmative answer ??");
						response == str(raw_input());
						if response == "yes":
							sexornot();
						else:
							nohit();
					else:
						nohit();
	else :
		print "i'm curious, what kinda name is", mname;
		print ("\nare you chinese??? -__- \n");
def start():
	print ("welcome to my hilarious algorithm");
	begin();

def begin():
	print ("enter your name :");
	mname = str(raw_input());
	print ("now enter her name :");
	gname = str(raw_input());
	chanceornot(mname, gname, 30);

start();
