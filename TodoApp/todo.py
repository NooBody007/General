from flask import Flask,render_template,url_for,redirect,request
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)

app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:////Users/efpla/OneDrive/Masaüstü/TodoApp/todo.db'
db = SQLAlchemy(app)

class todo(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    title = db.Column(db.String(80))
    complete = db.Column(db.Boolean)

@app.route("/")
def index():
    todos = todo.query.all()
    return render_template("index.html", todos = todos)

@app.route("/add",methods = ["POST"])
def addTodo():
    title = request.form.get("title")
    newTodo = todo(title = title, complete = False)
    db.session.add(newTodo)
    db.session.commit()
    return redirect(url_for("index"))

@app.route("/complete/<string:id>")
def complete(id):
    Todo = todo.query.filter_by(id = id).first()
    Todo.complete = not Todo.complete
    db.session.commit()
    return redirect(url_for("index"))

@app.route("/delete/<string:id>")
def delete(id):
    Tododel = todo.query.filter_by(id = id).first()
    db.session.delete(Tododel)
    db.session.commit()
    return redirect(url_for("index"))


if __name__ == "__main__":
    db.create_all()
    app.run(debug=True)
