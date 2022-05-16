using UnityEngine;

namespace CompleteProject
{
	public class EnemyManager : MonoBehaviour
	{
		public PlayerHealth playerHealth;       // Reference to the player's heatlh.
		public GameObject enemy;                // The enemy prefab to be spawned.
		public float spawnTime = 3f;            // How long between each spawn.
		public Transform[] spawnPoints;         // An array of the spawn points this enemy can spawn from.


		public float time
		{
			get;
			private set;
		}


		private void Update()
		{
			if (time >= spawnTime)
			{
				Spawn();
				time -= spawnTime;
			}

			time += Time.deltaTime;
		}


		public void AdvanceTime(float time)
		{
			this.time += time;
		}


		void Spawn()
		{
			// If the player has no health left...
			if (playerHealth.currentHealth <= 0f)
			{
				// ... exit the function.
				return;
			}

			// Find a random index between zero and one less than the number of spawn points.
			int spawnPointIndex = Random.Range(0, spawnPoints.Length);

			// Create an instance of the enemy prefab at the randomly selected spawn point's position and rotation.
			GameObject instance = Instantiate(enemy, spawnPoints[spawnPointIndex].position, spawnPoints[spawnPointIndex].rotation);
			instance.name = enemy.name;
		}
	}
}
