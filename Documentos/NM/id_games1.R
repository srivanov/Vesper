library("httr")
library("jsonlite")
query <- "https://igdbcom-internet-game-database-v1.p.mashape.com/games/?fields=id&offset=2&limit=10"


r <- GET(url=query,
         add_headers(.headers = c('X-Mashape-Key' =  "l75yqzAZyVmshBB70018LMfrb7vMp15hRk5jsnLPK9ZNp4iMp1" , 
                                  Accept =   "application/json")))
print(r)
doc<-fromJSON(content(r,type="text"))
print(doc)
