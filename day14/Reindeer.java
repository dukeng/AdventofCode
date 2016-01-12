package day14;

public class Reindeer {
	private String name;
	private int speed;
	private int time;
	private int rest;
	private int currentDistance;// for part 2
	private int point; // for part 2

	public Reindeer(String name, String speed, String time, String rest) {
		this.name = name;
		this.speed = Integer.parseInt(speed);
		this.time = Integer.parseInt(time);
		this.rest = Integer.parseInt(rest);
	}

	public void setcurrentDistance(int currentDistance) {
		this.currentDistance = currentDistance;
	}

	public void addPoint() {
		point++;
	}

	public int getPoint() {
		return point;
	}

	public int calculate() {
		int total = time + rest;
		int remain = 2503 % total;
		int times = 2503 / total;
		int distance;
		if (remain < time) {
			distance = times * speed * time + remain * speed;
		} else {
			distance = (times + 1) * speed * time;
		}
		return distance;

	}

	public void calculatePerSecond(int k) {
		int total = time + rest;
		int remain = k % total;
		int times = k / total;

		if (remain < time) {
			currentDistance = times * speed * time + remain * speed;

		} else {
			currentDistance = (times + 1) * speed * time;
		}
	}

	public int getTempDistance() {
		return currentDistance;
	}

	public String getName() {
		return name;
	}

}
