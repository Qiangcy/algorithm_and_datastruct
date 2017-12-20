from pymongo import MongoClient
import pymongo
import datetime
client = MongoClient('192.168.0.122', 12002, w=0)

#pymongo.write_concern.WriteConcern(w=0)
db = client.test_database
collection = db['test-collection']
post = {"author": "Mike",
        "text": "My first blog post!",
        "tags": ["mongodb", "python", "pymongo"],
        "date": datetime.datetime.utcnow()}
posts = db.posts
post_id = posts.insert_one(post).inserted_id
print post_id
