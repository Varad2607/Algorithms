class test:
    def __init(self):
        pass

    def trial_1(self,result):
        self.result=[1,2,3]
        print(result)

    def trial_2(self,result):
        result=[3,4,5]

    def func(self):
        self.result=[]
        self.trial_1(self.result)
        print(self.result)
        self.trial_2(self.result)
        print(self.result)



obj=test()
obj.func()