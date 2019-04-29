class App < Sinatra::Base
  get '/' do
    @data = db['SELECT comment FROM posts;'].all
    slim :home
  end

  post '/post' do
    insert_ds = db['INSERT INTO posts (comment) VALUES(?);', params['post']]
    insert_ds.insert
    redirect '/'
  end

  def db
    @db ||= Sequel.connect('postgres://security:qwerty@0.0.0.0:5432/super_secure_db')
  end
end
