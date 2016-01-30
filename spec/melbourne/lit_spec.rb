describe "A Lit node" do
  parse "0b1111" do
    [:lit, 15]
  end

  parse "1.1" do
    [:lit, 1.1]
  end

  parse "0xffffffffffffffff" do
    [:lit, 18446744073709551615]
  end

  parse "0xffff_ffff_ffff_ffff" do
    [:lit, 18446744073709551615]
  end

  parse "07654" do
    [:lit, 4012]
  end

  parse "-1" do
    [:lit, -1]
  end

  parse "1" do
    [:lit, 1]
  end

  parse "3r" do
    [:lit, (3/1)]
  end

  parse "1/3r" do
    [:call, [:lit, 1], :/, [:arglist, [:lit, (3/1)]]]
  end

  parse "2i" do
    [:lit, (0+2i)]
  end

  parse "3+2i" do
    [:call, [:lit, 3], :+, [:arglist, [:lit, (0+2i)]]]
  end

  parse "8000_0000" do
    [:lit, 80000000]
  end

  parse ":x" do
    [:lit, :x]
  end

  parse ":\"*args\"" do
    [:lit, :"*args"]
  end
end
