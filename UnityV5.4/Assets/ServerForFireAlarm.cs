﻿using System;
using System.Collections;
using System.Collections.Generic;
using System.Threading;
using System.Net;
using UnityEngine;
using UnityEngine.UI;
using System.Net.Sockets;
using System.Text;
using UnityEngine.SceneManagement;

public class ServerForFireAlarm : MonoBehaviour
{
    [SerializeField]
    //private Canvas panelPayment;

    public TcpListener server;

    //Default host and port
    string host = "127.0.0.1";
    int portFireAlarm = 10004;
    private string displaymessage = "";
    //public Text connectionStatus;
    //public Text variable;
    float fireAlarmfromServer;
    bool isChecking=false;
    Thread tcpListenerThread;

    public GameObject fireAlarm;

    // Use this for initialization
    public void Start()
    {
        fireAlarmfromServer=0f;
        tcpListenerThread = new Thread(() => ListenForMessages());
        tcpListenerThread.Start();
        displaymessage = "Not Connected!";
    }

    public void Update()
    {
        if(fireAlarmfromServer<0.5f){
            fireAlarm.SetActive(false);
        }else{
            fireAlarm.SetActive(true);
        }
        
        //displayConnectionStatus();
        //displayVariable();
        // if(isChecking==false){
        //     isChecking=true;
        //     StartCoroutine(CheckFireAlarmStatus());
        //     isChecking=false;
        // }

    }
    // IEnumerator CheckFireAlarmStatus(){
    //     if(fireAlarmfromServer==0f){
    //         fireAlarm.SetActive(false);
    //     }else{
    //         fireAlarm.SetActive(true);
    //     }
    //     yield return new WaitForSeconds(4);        
    // }

    public void ListenForMessages()
    {

        try
        {
            // Set the TcpListener on port 13000.
            IPAddress localAddr = IPAddress.Parse(host);

            // TcpListener server = new TcpListener(port);
            server = new TcpListener(localAddr, portFireAlarm);

            // Start listening for client requests.
            server.Start();

            // Buffer for reading data
            Byte[] bytes = new Byte[1024];      //The byte array containing the sequence of bytes to decode.
            String data = null;
            int counter = 0;
            // Enter the listening loop.
            while (true)
            {
                if (counter == 0)
                {
                    //counterForScene = 0;
                    displaymessage = "Waiting for a connection...";
                    Debug.Log(displaymessage);
                }

                // Perform a blocking call to accept requests.
                // You could also user server.AcceptSocket() here.
                using (TcpClient client = server.AcceptTcpClient())
                {

                    if (counter == 0)
                    {
                        displaymessage = "Connected!";
                        Debug.Log(displaymessage);
                        counter = 1;
                        //counterForScene = 1;
                    }

                    data = null;

                    // Get a stream object for reading and writing
                    NetworkStream stream = client.GetStream();

                    int i;      //The number of bytes to decode

                    // Loop to receive all the data sent by the client.
                    while ((i = stream.Read(bytes, 0, bytes.Length)) != 0)
                    {
                        // Translate data bytes to a ASCII string.
                        data = System.Text.Encoding.ASCII.GetString(bytes, 0, i);  // 0 is The index of the first byte to decode.
                        float fireAlarmfromRhapsody = (float)Convert.ToDouble(data);
                        //Debug.Log(data);
                        fireAlarmfromServer = fireAlarmfromRhapsody;

                        // Process the data sent by the client.

                        data = data.ToUpper();
                        //data = "0.01";
                        byte[] msg = System.Text.Encoding.ASCII.GetBytes(data);

                        // Send back a response.
                        stream.Write(msg, 0, msg.Length);
                        //Debug.Log("FireAlarm: " + fireAlarmfromServer.ToString());
                    }
                    // Shutdown and end connection
                    client.Close();
                }


            }
        }
        catch (SocketException e)
        {
            Debug.LogError(String.Format("SocketException: {0}", e));
        }
        finally
        {
            // Stop listening for new clients.
            server.Stop();
        }
    }

    //public void OnConnectButton()
    //{
    //    //Overwrite default host / port values 
    //    String h;
    //    h = GameObject.Find("HostInput").GetComponent<InputField>().text;
    //    if (h != "")
    //        host = h;
    //    Start();
    //}

    //void displayConnectionStatus()
    //{
    //    //connectionStatus.text = displaymessage;
    //}

    //void displayVariable()
    //{
    //    //variable.text = variablefromServer.ToString();
    //    Debug.Log("Working fine, value received is: " + variablefromServer.ToString());
    //}
}