# Miner 

  

**Ömer** is a miner who passionately does his job. One day **Serhat** wanted to work with **Ömer** on a project and went to **Ömer** with an offer. **Serhat**  had a schema of the mines and offer to **Ömer**. He offered that :

- I have a coal mine and schema of it. I want you to dig to that mine and extract the coal mines by yourself.
- I have limited amount of woods so that you can only create total of **k** meter tunnel.  
- Since I give you the schema of the mine, you should aim to extract as much coal mine as possible by inspecting the schema. Don't forget, the more coal you bring me the more money you will get !.
 
Serhat also says that you can only reach to the root of the mine at the beginning . Every path is closed and needs to be opened and tunneled by using the woods. When a path is tunneled **Ömer** can use the tunnel as many time as he wants to reach and carry out the coal mines from that tunnels.
A coal mine can only be extracted from its mining zone and carried out to outside if and only if there exist a tunnel from root to that mining zone. In other words the mining zone should be reachable.

Also when a tunnel is opened from root to a mining zone he can get all the mines there.

Given the scheme of the mine ( in the form of binary tree with path lengths and mining regions containing mines ) and maximum amount of tunnel can be created using woods **k (in meters)** , find the maximum amount of mine that can be extracted. (Root starts with 1) 

Visualization of sample : 

<a href="https://imgbb.com/"><img src="https://i.ibb.co/tL63BdB/explanation.png" alt="explanation" border="0" width="400" height="400"></a>


## Input Format

Number of nodes **n** and maximum tunnel length **k**  that can be created with given woods
Next **n** lines containing nodes and their coal amount (in kg).
Preceding **n-1**  lines containing edges and weights  in the format :  **source** - **destination** - **length of edge** .


## Output Format
Single integer, maximum amount of coal that can be extracted.


## Constraints 
1<=n<=10^4
1<=k<=500

## Sample Test Cases

### 1. Test case
#### Input
- 7 20
3 1 6 4 8 9 5
1 2 5
1 3 1
2 4 3
2 5 7
3 6 12
3 7 6
#### Output
- 23

Image of the tree with path highlighted will be added.




### 2. Test case
#### Input
- 5 39
359 963 465 706 146 
1 2 282
1 3 282
2 4 828
2 5 828

#### Output
- 359 
Since the only mining zone can be extracted is the root and no more mining zone can be extracted answer is the kg of coal in the root.

Image of the tree with path highlighted will be added.


