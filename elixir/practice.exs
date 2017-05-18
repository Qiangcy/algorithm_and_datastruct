defmodule Challenge do
  def get_middle(str) do 
    if(rem(String.length(str)-1, 2) == 0) do  
      String.at(str, div(String.length(str)-1, 2))
    else
      String.slice(str, div(String.length(str)-1, 2)..div(String.length(str),2))
    end
  end
end

IO.puts Challenge.get_middle("")

defmodule Negator do
  def make_negative(num) when num>0 do
    -num
  end
  def make_negative(num) do
    num
  end
end

defmodule Codewars do
  def remove_exclamation_marks(s) when s == "", do: ""
  def remove_exclamation_marks(s) do
    if(String.first(s) != "!") do
      String.first(s) <> remove_exclamation_marks(String.slice(s, 1, String.length(s)+1))
    else
      remove_exclamation_marks(String.slice(s, 1, String.length(s)+1))
    end
  end
end
IO.puts Codewars.remove_exclamation_marks(" ")

defmodule Codewars do
  def remove_exclamation_marks(s) do
    String.replace(s, "!", "")
  end
end

defmodule Oscar do
  def leo(oscar) do
    cond do
      oscar == 88 ->
        "Leo finally won the oscar! Leo is happy"
      oscar == 86 ->
        "Not even for Wolf of wallstreet?!"
      oscar < 88 ->
         "When will you give Leo an Oscar?"
      oscar > 88 ->
        "Leo got one already!"
    end
  end
end

defmodule Fnwithfn do
  def always(n) do
    fn -> n end
  end
end

defmodule Evenator do
  def even?(n) when is_float(n) do
    false
  end
  def even?(n) do
    cond do
      rem(n, 2)==0 -> true
      rem(n, 2)!=0 -> false
    end
  end
end
