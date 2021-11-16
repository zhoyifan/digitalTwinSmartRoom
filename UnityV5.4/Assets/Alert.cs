using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Alert : MonoBehaviour
{
    public bool isFlickering = false;
    public float timeDelay=2;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (isFlickering == false) {
            StartCoroutine(FlickeringLight());
        }
    }
    IEnumerator FlickeringLight() {
        isFlickering = true;
        this.GetComponent<Renderer>().material.color = Color.white;
        this.GetComponent<Light>().enabled = false;
        yield return new WaitForSeconds(timeDelay);
        this.GetComponent<Renderer>().material.color = Color.red;
        this.GetComponent<Light>().enabled = true;
        yield return new WaitForSeconds(timeDelay);
        isFlickering = false;
    }
}
