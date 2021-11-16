using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
public class MouseInPositionScript : MonoBehaviour  //on camera
{
    bool CursorLockedVar;

    void Start()
    {
        Cursor.lockState = CursorLockMode.None;
        Cursor.visible = (true);
        CursorLockedVar = (false);
    }

    void Update()
    {
        if (Input.GetKeyDown("escape") && CursorLockedVar)
        {
            Cursor.lockState = CursorLockMode.None;
            Cursor.visible = (true);
            CursorLockedVar = (false);
        }
        else if (Input.GetKeyDown("escape") && !CursorLockedVar)
        {
            Cursor.lockState = CursorLockMode.Locked;
            Cursor.visible = (true);
            CursorLockedVar = (true);
        }
    }
}