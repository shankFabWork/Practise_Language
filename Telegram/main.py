from telegram.ext import (Updater,CommandHandler,ConversationHandler,MessageHandler,Filters,CallbackContext)
from telegram import KeyboardButton,ReplyKeyboardMarkup,Update 
from memory_datasource import MemoryDataSource
import threading

TOKEN = "5236676435:AAGdDrjr6N4cm8sP6lMeOwnZWuC4M8iB5r8"
ENTER_MESSAGE, ENTER_TIME = range(2)
dataSource = MemoryDataSource()
Add_remainder_text = "Please add a remainder"
Interval = 3

def start_handler(update,context):
    update.message.reply_text("Hello, creator! papa",reply_markup = add_remainder_button())

def add_remainder_button():
    keyboard = [[KeyboardButton(Add_remainder_text)]]
    return ReplyKeyboardMarkup(keyboard)

def add_remainder_handler(update:Update,context:CallbackContext):
    update.message.reply_text("Please enter a message of the remainder")
    return ENTER_MESSAGE

def enter_message_handler(update:Update,context:CallbackContext):
    update.message.reply_text("Please enter a time when bot should remaind you \n please write the time in the format of '%d/%m/%Y %H:%M' like this '10/4/2022 11:58' ")
    context.user_data["message_text"] = update.message.text
    return ENTER_TIME

def enter_time_handler(update:Update,context:CallbackContext):
    message_text = context.user_data["message_text"]
    time = update.message.text
    message_data = dataSource.add_reminder(update.message.chat_id,message_text,time)
    update.message.reply_text("Your remainder "+message_data.__repr__())
    return ConversationHandler.END

def start_check_reminders_task():
    thread = threading.Thread(target=check_reminders,args=())
    thread.daemon = True
    thread.start()

def check_reminders():
    while True:
        for chat_id in dataSource.reminders:
            reminder_data = dataSource.reminders[chat_id]
            if reminder_data.should_be_fired():
                reminder_data.fire()
                updater.bot.send_message(chat_id, reminder_data.message)
        time.sleep(Interval)

if __name__ == "__main__":
    updater = Updater(TOKEN,use_context = True)
    updater.dispatcher.add_handler(CommandHandler("start",start_handler))
    conv_handler = ConversationHandler(
        entry_points = [MessageHandler(Filters.regex(Add_remainder_text),add_remainder_handler)],
        states = {
            ENTER_MESSAGE: [MessageHandler(Filters.all,enter_message_handler)],
            ENTER_TIME: [MessageHandler(Filters.all,enter_time_handler)]
        },
        fallbacks=[]
    )
    updater.dispatcher.add_handler(conv_handler)
    updater.start_polling()



# classtelegram.ReplyKeyboardMarkup(keyboard, resize_keyboard=False, one_time_keyboard=False, selective=False, input_field_placeholder=None, **_kwargs)