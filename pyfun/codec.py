def getLetterGrade(score):
	if score >= 90:
		return "A";
	elif 80 <= score < 90:
		return "B";
	elif 70<= score < 80:
		return "C";
	elif 60 <= score < 70:
		return "D";
	else:
		return "F";

print getLetterGrade(int(50));