class business:
    def __init__(self):
        self.name=None
        self.age=None
        self.salary=None
        self.company=None
        self.position=None

    def accounting(self):
        print("Accounting")
        self.header=["Name","Age","Salary","Company","Position"]

vikrant=business()
vikrant.name="Vikrant"
vikrant.age=25
vikrant.salary=100000
vikrant.company="Google"
vikrant.position="Software Engineer"
# vikrant.accounting()
vikrant.header=["Name"]
print(vikrant.header)
vikrant.header=0
print(vikrant.header)


vara=business()
