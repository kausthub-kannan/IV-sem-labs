// PlacementIndicator Script
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR.ARFoundation;
using UnityEngine.XR.ARSubsystems;

public class PlacementIndicator : MonoBehaviour
{
    private ARRaycastManager rayManager;
    private GameObject visual;

    // Start is called before the first frame update
    void Start()
    {
        rayManager = FindObjectOfType<ARRaycastManager>();
        visual = transform.GetChild(0).gameObject;
        
        // Hide placement indicator
        visual.SetActive(false);
    }

    // Update is called once per frame
    void Update()
    {
        List<ARRaycastHit> hits = new List<ARRaycastHit>();
        
        // Shoot raycast from center of screen
        rayManager.Raycast(new Vector2(Screen.width / 2, Screen.height / 2), hits, TrackableType.Planes);
        
        // If we hit AR plane update position and rotation
        if (hits.Count > 0)
        {
            transform.position = hits[0].pose.position;
            transform.rotation = hits[0].pose.rotation;
            
            if (!visual.activeInHierarchy)
                visual.SetActive(true);
        }
    }
}

// SpwanManager Script
using UnityEngine;

public class spawn_object : MonoBehaviour
{
    public GameObject objectToSpawn;
    private PlacementIndicator PlaceIndicate;

    void Start()
    {
        PlaceIndicate = FindObjectOfType<PlacementIndicator>();
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.touchCount > 0 && Input.touches[0].phase == TouchPhase.Began)
        {
            showobject();
        }
    }

    void showobject()
    {
        GameObject obj = Instantiate(objectToSpawn,
                                     PlaceIndicate.transform.position,
                                     PlaceIndicate.transform.rotation);
    }
}