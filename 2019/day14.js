//@ts-check

let Costs = [];
let Relationships = [];

function readInput(input)
{
  let relations = input.split("\n");
  for(let i = 0; i < relations.length; i++)
  {
    readLine(relations[i]);
  }
}

function readLine(line)
{
  let splitLine = line.split(" ");

  if(splitLine[1] == "ORE")
  {
    Costs.push({name: splitLine[3], quantity: parseInt(splitLine[2]), cost: parseInt(splitLine[0])});
  }
  else
  {
    let result = {name: splitLine[splitLine.length-1], quantity: splitLine[splitLine.length-2]};
    let formula = [];
    for(let i = 0; i < splitLine.length - 2; i += 2)
    {
      formula.push({name: splitLine[i+1], quantity: parseInt(splitLine[i])});
    }

    Relationships.push({result: result, formula: formula});
  }
}

function findFormulaForNode(node)
{
  for(let i = 0; i < Relationships.length; i++)
  {
    if(Relationships[i].result.name == node)
    {
      return Relationships[i];
    }
  }
}

function isPrimary(node)
{
  for(let i = 0; i < Costs.length; i++)
  {
    if(Costs[i].name == node)
    {
      return true;
    }
  }
  return false;
}

function dfs(quantity, node)
{
  let relation = findFormulaForNode(node);
  console.log(relation);
}

function main(input)
{
  readInput(input);

  console.log(dfs(1, "FUEL"));
}

module.exports = {main};