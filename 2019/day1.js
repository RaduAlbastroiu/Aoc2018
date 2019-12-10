//@ts-check

function main(input)
{
  let result = 0;
  let values = input.split("\n")
  values.forEach(value => {
    while(value > 0)
    {
      value = Math.max(Math.floor(parseInt(value, 10) / 3) - 2, 0);
      result += value;
    }
  });
  console.log(result);
}


module.exports = {main};