using UnityEngine;
using System;
using System.IO;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.Collections;
using System.Collections.Generic;

[DisallowMultipleComponent]
public class DesktopInputManager : MonoBehaviour
{
    public GameObject gotest;
    public GameObject gotest1;

    private float sim_test;
    private float sim_test1;

    //these are the value that I want to change and send to Simulink
    public float send_test = 0;
    public float send_test1 = 0;

    readonly string host = "0.0.0.0";
    readonly int port = 54320;
    Thread ListenerThread;
    UdpClient client = new UdpClient();

    void Stop()
    {

        client.Close();

        ListenerThread.Join();
        ListenerThread.Abort();

        client = new UdpClient();

    }

    public void ListenForMessages()
    {

        while (true)
        {

            Byte[] bytes = new Byte[1024];
            var remoteEP = new IPEndPoint(IPAddress.Parse(host), port);
            client.Client.Bind(remoteEP);
            var from = new IPEndPoint(0, 0);

            float testFromRhapsody = 0;
            float test1FromRhapsody = 0;

            while (true)
            {
                string rx_line = System.Text.Encoding.Default.GetString(client.Receive(ref from));
                string[] rx_array = rx_line.Split(new string[] { "," }, StringSplitOptions.None);
                //yahaan pe change karna hai
                if (rx_array.Length == 2)
                {
                    if (float.TryParse(rx_array[0], out testFromRhapsody))
                    {
                        this.sim_test = testFromRhapsody;
                    }
                    if (float.TryParse(rx_array[1], out test1FromRhapsody))
                    {
                        this.sim_test1 = test1FromRhapsody;
                    }
                }
                string test_val_str = String.Format("{0:F4}", send_test);
                string test1_val_str = String.Format("{0:F4}", send_test1);
                string str = test_val_str + "," + test1_val_str;
                var str_to_send = str;
                var byte_array = Encoding.GetEncoding("UTF-8").GetBytes(str_to_send);
                client.Send(byte_array, str_to_send.Length, from.Address.ToString(), from.Port);
            }
        }

    }

    void Start()
    {
        ListenerThread = new Thread(() => ListenForMessages());
        ListenerThread.Start();

    }

    // Update is called once per frame
    void Update()
    {
        Debug.Log("Test value " + this.sim_test + "\n");
        Debug.Log("Test1 value " + this.sim_test1 + "\n");
        //end
    }
}
