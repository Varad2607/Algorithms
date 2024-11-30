#!/usr/bin/env python3
# String concatanation (aka how to put the string together)
# Create a string that says  subscribe to a youtuber

youtuber="Varad Dhat" #some string variable

# Multiple ways to do this kind of problems

print("subscribe to " + youtuber)
print("subscribe to {}".format(youtuber))
print(f"subscribe to {youtuber}")

blank1=str(input("Blank1: "))
blank2=input("blank2: ")
verb3=input("verb3: ")
madlib=f"""Computer programmming is so {blank1}! It makes me so excited all the time because I love to {blank2}.
Stay hydrated always like you are a famous person {verb3}."""


print(madlib)