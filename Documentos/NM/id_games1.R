library("httr")
library("jsonlite")
#query <- "https://igdbcom-internet-game-database-v1.p.mashape.com/games/?fields=id&offset=2&limit=20"
#query <- "https://igdbcom-internet-game-database-v1.p.mashape.com/people/?fields=id&offset=2&limit=15"
query <- "https://igdbcom-internet-game-database-v1.p.mashape.com/people/?fields=*"
#query <- "https://igdbcom-internet-game-database-v1.p.mashape.com/characters/?fields=name&limit=50"
#query <- "https://igdbcom-internet-game-database-v1.p.mashape.com/characters/?fields=id&name&created_at&updated_at&slug&url&people&games&limit=50"
#query <- "https://igdbcom-internet-game-database-v1.p.mashape.com/characters/?fields=*&limit=10"

r <- GET(url=query,
         add_headers(.headers = c('X-Mashape-Key' =  "l75yqzAZyVmshBB70018LMfrb7vMp15hRk5jsnLPK9ZNp4iMp1" , 
                                  Accept =   "application/json")))
print(r)
doc<-fromJSON(content(r,type="text"))
print(doc)

file.create("character.csv")
#write.csv(r, 'miDoc.csv') comentado
#notas<-read.table(doc) comentado
write.table(doc, file = "character.csv")
#write.table(doc, file = "character.csv", append = TRUE, sep = ";", dec = ",",quote = FALSE,col.names = NA, qmethod = "double")



