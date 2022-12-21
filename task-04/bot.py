import os
import telebot
import requests

# TODO: 1.1 Get your environment variables
bot_id = os.environ['bot_id']
api_key = os.environ['api_key']

bot = telebot.TeleBot(bot_id)

@bot.message_handler(commands=['start', 'hello'])
def greet(message):
    global botRunning
    botRunning = True
    bot.reply_to(
        message, 'Hello there! I am a bot that will show movie information for you and export it in a CSV file.\n\n')
    
@bot.message_handler(commands=['stop', 'bye'])
def goodbye(message):
    global botRunning
    botRunning = False
    bot.reply_to(message, 'Bye!\nHave a good time.')
    


@bot.message_handler(func=lambda message: botRunning, commands=['help'])
def helpProvider(message):
    bot.reply_to(message, '1.0 You can use \"/movie MOVIE_NAME\" command to get the details of a particular movie. For eg: \"/movie The Shawshank Redemption\"\n\n2.0. You can use \"/export\" command to export all the movie data in CSV format.\n\n3.0. You can use \"/stop\" or the command \"/bye\" to stop the bot.')


@bot.message_handler(func=lambda message: botRunning, commands=['movie'])
def getMovie(message):
    url = "http://www.omdbapi.com/?apikey=" + api_key + "&t=" + message.text[7:].replace(" ","%20")
    bot.reply_to(message, 'Getting movie info...')
    # TODO: 1.2 Get movie information from the API
    data = requests.get(url).json()
    # TODO: 1.3 Show the movie information in the chat window
    details = "Title: " + data['Title'] + "\nYear of Release: " + data['Year'] + "\nIMDB Rating: " + data['imdbRating']
    bot.reply_to(message, details)

    # TODO: 2.1 Create a CSV file and dump the movie information in it
    f = open("movie.csv", "a")
    f.write(data['Title'] + ',' + data['Year'] + ',' + data['imdbRating'] + '\n')
    f.close()

  
@bot.message_handler(func=lambda message: botRunning, commands=['export'])
def getList(message):
    bot.reply_to(message, 'Generating file...')
    #TODO: 2.2 Send downlodable CSV file to telegram chat
    doc = open('movie.csv', 'rb')
    bot.send_document(message.chat.id, doc)

@bot.message_handler(func=lambda message: botRunning)
def default(message):
    bot.reply_to(message, 'I did not understand. '+'\N{confused face}')
    
bot.infinity_polling()