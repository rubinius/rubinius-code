describe "An Back_ref node" do
  parse "[$&, $`, $', $+]" do
    [:array,
     [:back_ref, :&],
     [:back_ref, :`],
     [:back_ref, :"'"],
     [:back_ref, :+]]
  end
end
