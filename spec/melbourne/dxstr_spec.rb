describe "A Dxstr node" do
  parse <<-ruby do
      t = 5
      `touch \#{t}`
    ruby

    [:block, [:lasgn, :t, [:lit, 5]], [:dxstr, "touch ", [:evstr, [:lvar, :t]]]]
  end
end
