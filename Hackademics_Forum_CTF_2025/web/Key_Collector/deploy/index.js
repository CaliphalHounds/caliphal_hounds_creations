const express = require('express')

const app = express()
app.use(express.urlencoded({ extended: true}))
const port = 7777
const flag = process.env.FLAG

app.use(function(err, req, res, next) {
    res.status(500).send("An error occurred!")
})


function dataSet(data) {
    this.note = data["block1"]["note"]
    this.book = data["block1"]["book"]
    this.lunch = data["block2"]["lunch"]
    this.fakeFlag = data["block1"]["fakeFlag"]
    this.flag = flag
}



app.get("/", (req, res) => {
    res.send("We have updated the website! Check /data")
})

app.get("/data", (req, res) => {
    res.send("Try to get the flag if you can!")
})

app.post("/data", (req, res) => {
    data = {"block1":{"note":"Give me some notes","book": "The Hunger Games"}, "block2":{"lunch":"Fish and chips"}}

    try {
        if (req.body.key == "__proto__" && req.body.key2 == "toString") {

        } else {
            data[req.body.key][req.body.key2] = flag;
        }
        data["block1"]["note"] = req.body.note

        resText = new dataSet(data);
        delete data.__proto__.note

    } catch (err) {
        res.status(500).send("An error occurred!")
    }
    res.send("Here's your note: " + resText["note"])
})



app.listen(port, () => { console.log("Server running!") })
