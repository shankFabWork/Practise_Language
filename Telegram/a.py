import os
import telebot

TOKEN = "5236676435:AAGdDrjr6N4cm8sP6lMeOwnZWuC4M8iB5r8"
bot = telebot.TeleBot(TOKEN)

@bot.message_handler(commands=['Greet'])
def greet(message):
  bot.reply_to(message, "Hey! Hows it going?")

@bot.message_handler(commands=['hello'])
def hello(message):
  bot.send_message(message.chat.id, "Hello!")

bot.polling()