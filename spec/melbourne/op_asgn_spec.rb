describe "An Op_asgn1 node" do
  parse "a &&= 8" do
    [:op_asgn_and, [:lvar, :a], [:lasgn, :a, [:lit, 8]]]
  end

  parse "hsh[:blah] ||= 8" do
    [:op_asgn1,
     [:call, nil, :hsh, [:arglist]],
     [:arglist, [:lit, :blah]],
     :"||",
     [:lit, 8]]
  end

  parse <<-ruby do
      x = 1
      hsh[x] ||= 8
    ruby

    [:block,
     [:lasgn, :x, [:lit, 1]],
     [:op_asgn1,
      [:call, nil, :hsh, [:arglist]],
      [:arglist, [:lvar, :x]],
      :"||",
      [:lit, 8]]]
  end

  parse "hsh[:blah] &&= 8" do
    [:op_asgn1,
     [:call, nil, :hsh, [:arglist]],
     [:arglist, [:lit, :blah]],
     :"&&",
     [:lit, 8]]
  end

  parse "hsh[:blah] ^= 8" do
    [:op_asgn1,
     [:call, nil, :hsh, [:arglist]],
     [:arglist, [:lit, :blah]],
     :^,
     [:lit, 8]]
  end

  parse "ary[0,1] += [4]" do
    [:op_asgn1,
     [:call, nil, :ary, [:arglist]],
     [:arglist, [:lit, 0], [:lit, 1]],
     :+,
     [:array, [:lit, 4]]]
  end

  parse "x.val ||= 6" do
    [:op_asgn2, [:call, nil, :x, [:arglist]], :val=, :"||", [:lit, 6]]
  end

  parse "x.val &&= 7" do
    [:op_asgn2, [:call, nil, :x, [:arglist]], :val=, :"&&", [:lit, 7]]
  end

  parse <<-ruby do
      @b = []
      @b[1] ||= 10
      @b[2] &&= 11
      @b[3] += 12
    ruby

    [:block,
     [:iasgn, :@b, [:array]],
     [:op_asgn1, [:ivar, :@b], [:arglist, [:lit, 1]], :"||", [:lit, 10]],
     [:op_asgn1, [:ivar, :@b], [:arglist, [:lit, 2]], :"&&", [:lit, 11]],
     [:op_asgn1, [:ivar, :@b], [:arglist, [:lit, 3]], :+, [:lit, 12]]]
  end

  parse <<-ruby do
      b = []
      b[1] ||= 10
      b[2] &&= 11
      b[3] += 12
    ruby

    [:block,
     [:lasgn, :b, [:array]],
     [:op_asgn1, [:lvar, :b], [:arglist, [:lit, 1]], :"||", [:lit, 10]],
     [:op_asgn1, [:lvar, :b], [:arglist, [:lit, 2]], :"&&", [:lit, 11]],
     [:op_asgn1, [:lvar, :b], [:arglist, [:lit, 3]], :+, [:lit, 12]]]
  end
end

describe "An Op_asgn2 node" do
  parse "x.val ^= 8" do
    [:op_asgn2, [:call, nil, :x, [:arglist]], :val=, :^, [:lit, 8]]
  end

  parse "self.Bag ||= Bag.new" do
    [:op_asgn2,
      [:self],
      :"Bag=", :"||", [:call, [:const, :Bag], :new, [:arglist]]]
  end

  parse <<-ruby do
      s = Struct.new(:var)
      c = s.new(nil)
      c.var ||= 20
      c.var &&= 21
      c.var += 22
      c.d.e.f ||= 42
    ruby

    [:block,
     [:lasgn, :s, [:call, [:const, :Struct], :new, [:arglist, [:lit, :var]]]],
     [:lasgn, :c, [:call, [:lvar, :s], :new, [:arglist, [:nil]]]],
     [:op_asgn2, [:lvar, :c], :var=, :"||", [:lit, 20]],
     [:op_asgn2, [:lvar, :c], :var=, :"&&", [:lit, 21]],
     [:op_asgn2, [:lvar, :c], :var=, :+, [:lit, 22]],
     [:op_asgn2,
      [:call, [:call, [:lvar, :c], :d, [:arglist]], :e, [:arglist]],
      :f=,
      :"||",
      [:lit, 42]]]
  end
end

describe "An Op_asgn_and node" do
  parse "@fetcher &&= new(Gem.configuration[:http_proxy])" do
    [:op_asgn_and,
     [:ivar, :@fetcher],
     [:iasgn,
      :@fetcher,
      [:call,
       nil,
       :new,
       [:arglist,
        [:call,
         [:call, [:const, :Gem], :configuration, [:arglist]],
         :[],
         [:arglist, [:lit, :http_proxy]]]]]]]
  end

  parse <<-ruby do
      a = 0
      a &&= 2
    ruby

    [:block,
     [:lasgn, :a, [:lit, 0]],
     [:op_asgn_and, [:lvar, :a], [:lasgn, :a, [:lit, 2]]]]
  end
end

describe "An Op_asgn_or node" do
  parse "@@var ||= 3" do
    [:op_asgn_or, [:cvar, :@@var], [:cvasgn, :@@var, [:lit, 3]]]
  end

  parse "a ||= 8" do
    [:op_asgn_or, [:lvar, :a], [:lasgn, :a, [:lit, 8]]]
  end

  parse <<-ruby do
      a ||= begin
              b
            rescue
              c
            end
    ruby

    [:op_asgn_or,
     [:lvar, :a],
     [:lasgn,
      :a,
      [:rescue,
       [:call, nil, :b, [:arglist]],
       [:resbody,
        [:array, [:const, :StandardError]],
        [:call, nil, :c, [:arglist]]]]]]
  end

  parse "@fetcher ||= new(Gem.configuration[:http_proxy])" do
    [:op_asgn_or,
     [:ivar, :@fetcher],
     [:iasgn,
      :@fetcher,
      [:call,
       nil,
       :new,
       [:arglist,
        [:call,
         [:call, [:const, :Gem], :configuration, [:arglist]],
         :[],
         [:arglist, [:lit, :http_proxy]]]]]]]
  end

  parse "@v ||= {  }" do
    [:op_asgn_or, [:ivar, :@v], [:iasgn, :@v, [:hash]]]
  end

  parse <<-ruby do
      a = 0
      a ||= 1
    ruby

    [:block,
     [:lasgn, :a, [:lit, 0]],
     [:op_asgn_or, [:lvar, :a], [:lasgn, :a, [:lit, 1]]]]
  end
end
