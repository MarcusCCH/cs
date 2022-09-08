
vector<vector<int>>adj;
int n;//number of nodes
int s;//source node (to start with)
queue<int> q;//to record the stuff
vector<bool> fired(n);//to record the fired situation
vecotr<int>d(n),p(n);
for(int i = 0;i<10;i++){
	fired[i] = false;
}
q.push(fired[s]);
int v;
p[s] = -1;
fired[s] = true;
while(!q.empty()){
	v = q.front();
	q.pop();//fuck it 
	for(int u : adj[v]){ //dunno how it works??? it is a 2d array 
		if(!fired[u]){
			fired[u] = true;// fire it up!
			d[u] = d[v]+1; // what the fuck is this ? 
			q.push(u); // push it to the queue to loop again
			p[u] = v; // this is to record the shortest path?
		}
	}
}
