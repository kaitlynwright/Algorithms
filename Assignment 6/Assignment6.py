import sys

def PhraseSplit(dictionary, phrase):
	if phrase in dictionary:							#base case, single word in dict
		return phrase

	for i in range(1, len(phrase)):						#iterate through phrase
		seg = phrase[0:i]								#segment the phrase
		if seg in dictionary:					
			seg2 = phrase[i:len(phrase)]				#check if next segment in phrase is in dictionary
			seg3 = PhraseSplit(dictionary, seg2)		
			if seg3 != None:
				return seg + " " + seg3					#return the valid words
	return None											#if no valid words, return None


def loadDict(dictFile):
	dictList = []
	f = open(dictFile, "r")

	for line in f:
		dictList.append(line.strip())
	return dictList


def main():
	dictionary = loadDict("diction10k.txt")
	c = int(sys.stdin.readline())

	for i in range(c):
		line = sys.stdin.readline().strip()
		print("Phrase number:", i + 1)
		print(line)

		phraseList = PhraseSplit(dictionary, line)
		
		if phraseList != None:						
			print("YES - can be split")
			print(phraseList, "\n")
		else:
			print("NO - cannot be split\n")


if __name__ == "__main__":
	main()