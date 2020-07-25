import sys
import re

if __name__ == "__main__":
   if(len(sys.argv) < 2):
      out = open("result.txt" , "w")
   elif(len(sys.argv)>=2):
      out = open("result.txt", "w")
      with open("covid-confirmed-us-subset.txt") as inputfile:
         for line in inputfile:
            if re.search(sys.argv[1], line):
               out.write(line)
else:
   exit()