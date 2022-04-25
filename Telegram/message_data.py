import datetime

class ReminderData:

    def __init__(self,message,time):
        self.message = message
        self.time = datetime.datetime.strptime(time, "%d/%m/%Y %H:%M")
        self.fired = False

    def __repr__(self):
        return "Message: {0}; At Time {1} ".format(self.message,self.time.strftime("%d/%m/%Y %H:%M"))

    def fire(self):
        self.fired = True

    def should_be_fired(self):
        return self.fired is False and datetime.datetime.today() >= self.time   