# defmodule StringUtils do
#   def is_upper(c) do
#     if("a"<=c && c<="z") do
#       false
#     else
#       true
#     end
#   end

#   def upper_case?(str) when str=="", do: true
#   def upper_case?(str) do
#     cond do
#       String.length(str)==1 -> is_upper(String.first(str))
#       !is_upper(String.first(str)) -> false
#       is_upper(String.first(str)) -> upper_case?(String.slice(str, 1..String.length(str)-1))
#     end
#   end
# end

# IO.puts StringUtils.upper_case?("b")
# IO.puts StringUtils.upper_case?("C")

# defmodule Plural do
#   def plural?(n) do
#     cond do
#       is_integer(n) -> "Plural for " <> Integer.to_string(n)
#       is_float(n) -> "Plural for " <> Float.to_string(n)
#     end
#   end
# end
# IO.puts Plural.plural?(0.5)
# IO.puts Plural.plural?(15)

defmodule Codewars do
  require Integer
  def even_or_odd(number) do
    if(Integer.is_even(number)) do
      "Even"
    else 
      "Odd"
    end
  end
end
IO.puts Codewars.even_or_odd(1) 
