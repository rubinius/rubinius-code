describe "A Dregx node" do
  parse <<-ruby do
      /(\#{})/
    ruby

    [:dregx, "(", [:evstr, [:nil]], [:str, ")"]]
  end

  parse "/x\#{(1 + 1)}y/" do
    [:dregx,
     "x",
     [:evstr, [:call, [:lit, 1], :+, [:arglist, [:lit, 1]]]],
     [:str, "y"]]
  end

  parse "/a\#{}b/" do
    [:dregx, "a", [:evstr, [:nil]], [:str, "b"]]
  end

  parse "/\#{@rakefile}/" do
    [:dregx, "", [:evstr, [:ivar, :@rakefile]]]
  end

  parse "/\#{1}/n" do
    [:dregx, "", [:evstr, [:lit, 1]], 512]
  end

  parse "/\#{IAC}\#{SB}/no" do
    [:dregx_once, "", [:evstr, [:const, :IAC]], [:evstr, [:const, :SB]], 512]
  end

  parse "/x\#{(1 + 1)}y/o" do
    [:dregx_once,
     "x",
     [:evstr, [:call, [:lit, 1], :+, [:arglist, [:lit, 1]]]],
     [:str, "y"]]
  end
end
