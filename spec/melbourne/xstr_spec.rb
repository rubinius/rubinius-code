describe "A Xstr node" do
  parse "`touch 5`" do
    [:xstr, "touch 5"]
  end
end
