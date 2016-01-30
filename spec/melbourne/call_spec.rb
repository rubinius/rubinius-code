describe "A Call node" do
  parse "self.method" do
    [:call, [:self], :method, [:arglist]]
  end

  parse "1.m(2)" do
    [:call, [:lit, 1], :m, [:arglist, [:lit, 2]]]
  end

  parse "h(1, 2, *a)" do
    [:call, nil, :h,
     [:arglist,
       [:lit, 1],
       [:lit, 2],
       [:splat, [:call, nil, :a, [:arglist]]]]]
  end

  parse <<-ruby do
      begin
        (1 + 1)
      end
    ruby

    [:call, [:lit, 1], :+, [:arglist, [:lit, 1]]]
  end

  parse "blah(*a)" do
    [:call, nil, :blah,
      [:arglist, [:splat, [:call, nil, :a, [:arglist]]]]]
  end

  parse "a.b(&c)" do
    [:call,
     [:call, nil, :a, [:arglist]],
     :b,
     [:arglist, [:block_pass, [:call, nil, :c, [:arglist]]]]]
  end

  parse "a.b(4, &c)" do
    [:call,
     [:call, nil, :a, [:arglist]],
     :b,
     [:arglist, [:lit, 4], [:block_pass, [:call, nil, :c, [:arglist]]]]]
  end

  parse "a.b(1, 2, 3, &c)" do
    [:call,
     [:call, nil, :a, [:arglist]],
     :b,
     [:arglist,
      [:lit, 1],
      [:lit, 2],
      [:lit, 3],
      [:block_pass, [:call, nil, :c, [:arglist]]]]]
  end

  parse "a(&b)" do
    [:call,
     nil,
     :a,
     [:arglist, [:block_pass, [:call, nil, :b, [:arglist]]]]]
  end

  parse "a(4, &b)" do
    [:call,
     nil,
     :a,
     [:arglist, [:lit, 4], [:block_pass, [:call, nil, :b, [:arglist]]]]]
  end

  parse "a(1, 2, 3, &b)" do
    [:call,
     nil,
     :a,
     [:arglist,
      [:lit, 1],
      [:lit, 2],
      [:lit, 3],
      [:block_pass, [:call, nil, :b, [:arglist]]]]]
  end

  parse "define_attr_method(:x, :sequence_name, &Proc.new { |*args| nil })" do
    [:call,
     nil,
     :define_attr_method,
     [:arglist,
      [:lit, :x],
      [:lit, :sequence_name],
      [:block_pass,
       [:call,
        [:const, :Proc],
        :new,
        [:arglist, [:iter, [:args, :"*args"], [:nil]]]]]]]
  end

  parse "r.read_body(dest, &block)" do
    [:call,
     [:call, nil, :r, [:arglist]],
     :read_body,
     [:arglist,
      [:call, nil, :dest, [:arglist]],
      [:block_pass, [:call, nil, :block, [:arglist]]]]]
  end

  parse "o.m(:a => 1, :b => 2)" do
    [:call,
     [:call, nil, :o, [:arglist]],
     :m,
     [:arglist, [:hash, [:lit, :a], [:lit, 1], [:lit, :b], [:lit, 2]]]]
  end

  parse "o.m(42, :a => 1, :b => 2)" do
    [:call,
     [:call, nil, :o, [:arglist]],
     :m,
     [:arglist,
      [:lit, 42],
      [:hash, [:lit, :a], [:lit, 1], [:lit, :b], [:lit, 2]]]]
  end

  parse "o.puts(42)" do
    [:call, [:call, nil, :o, [:arglist]], :puts, [:arglist, [:lit, 42]]]
  end

  parse "1.b(c)" do
    [:call, [:lit, 1], :b, [:arglist, [:call, nil, :c, [:arglist]]]]
  end

  parse "(v = (1 + 1)).zero?" do
    [:call,
     [:lasgn, :v, [:call, [:lit, 1], :+, [:arglist, [:lit, 1]]]],
     :zero?,
     [:arglist]]
  end

  parse "-2**31" do
    [:call,
     [:call, [:lit, 2], :**, [:arglist, [:lit, 31]]],
     :-@,
     [:arglist]]
  end

  parse "a[]" do
    [:call, [:call, nil, :a, [:arglist]], :[], [:arglist]]
  end

  parse "m(:a => 1, :b => 2)" do
    [:call,
     nil,
     :m,
     [:arglist, [:hash, [:lit, :a], [:lit, 1], [:lit, :b], [:lit, 2]]]]
  end

  parse "m(42, :a => 1, :b => 2)" do
    [:call,
     nil,
     :m,
     [:arglist, [:lit, 42], [:hash, [:lit, :a], [:lit, 1], [:lit, :b], [:lit, 2]]]]
  end

  parse "m(42)" do
    [:call, nil, :m, [:arglist, [:lit, 42]]]
  end

  parse "a(:b) { :c }" do
    [:call, nil, :a, [:arglist, [:lit, :b], [:iter, [:args], [:lit, :c]]]]
  end

  parse "a [42]" do
    [:call, nil, :a, [:arglist, [:array, [:lit, 42]]]]
  end

  parse "42 if block_given?" do
    [:if, [:call, nil, :block_given?, [:arglist]], [:lit, 42], nil]
  end

  parse "method" do
    [:call, nil, :method, [:arglist]]
  end

  parse <<-ruby do
      a << begin
             b
           rescue
             c
           end
    ruby

    [:call,
     [:call, nil, :a, [:arglist]],
     :<<,
     [:arglist,
      [:rescue,
       [:call, nil, :b, [:arglist]],
       [:resbody,
        [:array, [:const, :StandardError]],
        [:call, nil, :c, [:arglist]]]]]]
  end

  parse "meth([*[1]])" do
    [:call,
      nil,
      :meth,
      [:arglist, [:splat, [:array, [:lit, 1]]]]]
  end

  parse "meth(*[1])" do
    [:call, nil, :meth, [:arglist, [:splat, [:array, [:lit, 1]]]]]
  end
end
