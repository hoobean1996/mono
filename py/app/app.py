from flask import Flask
 
app = Flask(__name__)
 
@app.route('/')
def index():
  return 'hello world' 

@app.route('/html')
def html():
  return 'html'


if __name__ == '__main__':
  app.run(host='0.0.0.0', port=8888)