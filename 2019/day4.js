//@ts-check

function decreasing(number)
{
  let s = number.toString();

  for(let i = 0; i < s.length - 1; i++)
  {
    if(s[i] > s[i+1])
    {
      return true;
    }
  }
  return false;
}

function hasDouble(number)
{
  let s = number.toString();

  if(s[0] == s[1] && s[1] != s[2])
    return true;

  if(s[3]!= s[4] && s[4] == s[5])
    return true;

  for(let i = 1; i < s.length - 2; i++)
  {
    if(s[i] == s[i+1] && s[i-1] != s[i] && s[i+1] != s[i+2])
    {
      return true;
    }
  }

  return false;
}

function main(input)
{
  console.log(input);

  let left = input.split("-")[0];
  let right = input.split("-")[1];

  console.log(hasDouble(3445));

  let count = 0;
  for(let i = parseInt(left); i <= parseInt(right); i++)
  {
    if(hasDouble(i) && !decreasing(i))
    {
      count++;
    }
  }
  console.log(count);
}

module.exports = {main};