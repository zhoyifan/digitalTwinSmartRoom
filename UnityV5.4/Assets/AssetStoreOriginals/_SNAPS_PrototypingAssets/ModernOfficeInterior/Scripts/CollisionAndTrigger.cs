using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CollisionAndTrigger : MonoBehaviour
{
    public Light light;
//    public GameObject light6;

    // Start is called before the first frame update
    void Start()
    {
        light.enabled = false;
   }

    // Update is called once per frame
    void Update()
    {

    }

    private void OnTriggerEnter(Collider other)
    {
        Debug.Log(other.name + " Has Entered!");
        light.enabled = true;
    }
    private void OnTriggerExit(Collider other)
    {
        Debug.Log(other.name + " Has Exited!");
        light.enabled = false;
    }
    private void OnTriggerStay(Collider other)
    {
        //Debug.Log(other.name + " Is Staying");
    }
    //private void OnCollisionEnter(Collision collision)
    //{
    //    Debug.Log(collision.transform.name + " Has Collided With Me!");
    //}
    //private void OnCollisionExit(Collision collision)
    //{
    //    Debug.Log(collision.transform.name + " Has Stopped Colliding With Me!");
    //}
    //private void OnCollisionStay(Collision collision)
    //{
    //    Debug.Log(collision.transform.name + " Is Still Colliding With Me!");
    //}
}
