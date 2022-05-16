using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyMoviment : MonoBehaviour
{
    public Transform[] waypoints;
    private int speed = 1 ;
    private int waypointIndex;
    private float dist;
    // Start is called before the first frame update
    void Start()
    {
        waypointIndex = 0;
        transform.LookAt(waypoints[waypointIndex].position);
    }

    // Update is called once per frame
    void Update()
    {
        dist = Vector3.Distance(transform.position , waypoints[waypointIndex].position);
        if (dist< 1f){
            IncreaseIndex();
        }
        Patrol();
    }
    void Patrol(){
        transform.Translate(Vector3.forward * speed * Time.deltaTime);
        transform.Translate(Vector3.up * 0);
    }
    void IncreaseIndex(){
        waypointIndex ++;
        if (waypointIndex >= waypoints.Length){
            waypointIndex = 0;
        }
        transform.LookAt(waypoints[waypointIndex].position);
    }
}

