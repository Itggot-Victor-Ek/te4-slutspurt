require 'sequel'
require 'pp'
puts 'connecting to db'
db ||= Sequel.connect('postgres://security:qwerty@0.0.0.0:5432/super_secure_db')

puts 'dropping table'
db.run 'DROP TABLE IF EXISTS posts;'

puts 'creating tables'
db.run 'CREATE TABLE posts (comment VARCHAR(255) NOT NULL)'

puts 'inserting standard values'
db.run "INSERT INTO posts (comment) VALUES('helllooo');"

puts 'complete'
