using UnityEngine.EventSystems;
using UnityEngine;

public class SwitchWatch : MonoBehaviour
{
    public GameObject[] watchWindow;
    public GameObject[] watchModel;

    private Animator _anim1, _anim2;

    // Start is called before the first frame update
    void Start()
    {
        watchModel[0].SetActive(true);
        watchWindow[0].SetActive(true);
        watchModel[1].SetActive(false);
        watchWindow[1].SetActive(false);
        
        _anim1 = watchWindow[0].GetComponent<Animator>();
        _anim2 = watchWindow[1].GetComponent<Animator>();
    }

    // Update is called once per frame
    public void Watch1()
    {
        _anim1.SetBool("close", false);
        watchModel[0].SetActive(true);
        watchWindow[0].SetActive(true);
        watchModel[1].SetActive(false);
        watchWindow[1].SetActive(false);
    }

    public void Watch2()
    {
        _anim2.SetBool("close", false);
        watchModel[0].SetActive(false);
        watchWindow[0].SetActive(false);
        watchModel[1].SetActive(true);
        watchWindow[1].SetActive(true);
    }

    public void Close()
    {
        string buttonName = EventSystem.current.currentSelectedGameObject.name;
        if (buttonName == "Close1")
        {
            _anim1.SetBool("close", true);
        }
        else if (buttonName == "Close2")
        {
            _anim2.SetBool("close", true);
        }
      }
}