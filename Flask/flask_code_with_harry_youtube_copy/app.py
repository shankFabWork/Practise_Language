from flask import Flask,render_template,request,redirect
from flask_sqlalchemy import SQLAlchemy
from datetime import datetime

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///harry.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)

class Todo(db.Model):
    sno = db.Column(db.Integer,primary_key = True)
    title = db.Column(db.String(200),nullable = False)
    desc = db.Column(db.String(200),nullable = False)
    date_created = db.Column(db.DateTime,default = datetime.utcnow)

    def __repr__(self) -> str:
        return f"{self.sno} - {self.title}"

@app.route('/',methods = ['GET','POST'])
def hello_world():

    if request.method == "POST":
        print("post")
        title = (request.form['title'])
        desc = (request.form['desc'])
        todo = Todo(title = title,desc = desc)
        db.session.add(todo)
        db.session.commit()


    # return "Hello World"
    # todo = Todo(title = "first name",desc = "hello")
    # db.session.add(todo)
    # db.session.commit()
    return render_template("home.html",allTodo = Todo.query.all(),msg = "abcd")

@app.route('/products')
def products_page():

    all_data = Todo.query.all()
    print(all_data)
    return "This products pages"

@app.route('/delete/<int:sno>')
def delete(sno):
    todo = Todo.query.filter_by(sno = sno).first()
    db.session.delete(todo)
    db.session.commit()
    # print(all_data)
    # return "This products pages"
    return redirect("/")


@app.route('/update/<int:sno>',methods = ['GET','POST'])
def update_page(sno):
    each_data = Todo.query.filter_by(sno = sno).first()
    if request.method == "GET":
        pass
    if request.method == "POST":
        title = (request.form['title'])
        desc = (request.form['desc'])
        # todo = Todo(title = title,desc = desc)
        each_data.title = title
        each_data.desc = desc
        db.session.add(each_data)
        db.session.commit()
        return redirect("/")
    return render_template("update.html",each_data = each_data)


if __name__ == "__main__":
    app.run(debug = True,port = 8080)