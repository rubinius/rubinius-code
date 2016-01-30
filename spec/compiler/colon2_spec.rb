describe "A Colon2 node" do
  relates "X::Y" do
    compile do |g|
      g.push_const :X
      g.find_const :Y
    end
  end
end
