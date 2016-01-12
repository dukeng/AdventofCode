package day14;

public class Database {
	private String reindeerList[];
	private int reindeerDistance[];
	private Reindeer reindeer[];
	private int count;
	private int maxMax;
	private int currentMaxDistance;
	private int point;

	Database() {
		reindeerList = new String[9];
		reindeerDistance = new int[9];
		reindeer= new Reindeer[9];
	}
	

	public void setReindeer(int distance,int h){
		distance= reindeerDistance[h];
	}
	public void add(Reindeer a){
		reindeer[count]= a;
		count++;
	}
	public Reindeer getInfo(int k){
		return reindeer[k];
	}
	public void record(String name, int distance) {
		reindeerList[count] = name;
		reindeerDistance[count] = distance;
		count++;
	}

	public int getDistance(int a) {
		return reindeerDistance[a];
	}

	public void max(int a) {
		if (maxMax < a) {
			maxMax = a;
		}
	}

	public int getMax() {
		return maxMax;
	}

	public void comparedistance(int a) {
		if (currentMaxDistance < a) {
			currentMaxDistance = a;
		}

	}
	public void comparepoint(int point){
		if (this.point <point){
			this. point= point;
		}
	}
	public int returnPoint(){
		return point;
	}
	public int getcurrentmaxDistance() {
		return currentMaxDistance;
	}

	

}
