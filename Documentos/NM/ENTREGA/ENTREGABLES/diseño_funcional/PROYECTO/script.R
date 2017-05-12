library("httr")
library("jsonlite")

#query <- "https://igdbcom-internet-game-database-v1.p.mashape.com/characters/?fields=id,name,created_at,updated_at,slug,url&limit=50"
#query <- "https://igdbcom-internet-game-database-v1.p.mashape.com/companies/?fields=id,name,created_at,updated_at,slug,url,start_date_category,change_date_category&limit=50"
#query <- "https://igdbcom-internet-game-database-v1.p.mashape.com/feeds/?fields=id,created_at,updated_at,url,content,category,meta&limit=50"
#query <- "https://igdbcom-internet-game-database-v1.p.mashape.com/franchises/?fields=id,name,created_at,updated_at,slug,url&limit=50"
#query <- "https://igdbcom-internet-game-database-v1.p.mashape.com/game_modes/?fields=id,name,created_at,updated_at,slug,url&limit=50"
#query <- "https://igdbcom-internet-game-database-v1.p.mashape.com/games/?fields=id,name,slug,url,created_at,updated_at,collection,popularity&limit=50"
#query <- "https://igdbcom-internet-game-database-v1.p.mashape.com/genres/?fields=id,name,created_at,updated_at,slug,url&limit=50"
query <- "https://igdbcom-internet-game-database-v1.p.mashape.com/themes/?fields=id,name,created_at,updated_at,slug,url&limit=50"


r <- GET(url=query,
         add_headers(.headers = c('X-Mashape-Key' =  "l75yqzAZyVmshBB70018LMfrb7vMp15hRk5jsnLPK9ZNp4iMp1" , 
                                  Accept =   "application/json")))
#print(r)
doc<-fromJSON(content(r,type="text"))
print(doc)

file.create("themes.csv")
#write.csv(r, 'miDoc.csv')
#notas<-read.table(doc)
write.table(doc, file = "Desktop/themes.csv")

