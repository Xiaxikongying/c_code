using System.Collections;
using System.Collections.Generic;
using System.Text;
using UnityEngine;
using UnityEngine.UIElements;

public
class Calculator : MonoBehaviour
{
    void Start()
    {
        // 获取根视觉元素
        m_rootVisualElement = GetComponent<UIDocument>().rootVisualElement;
        // 获取数字
        m_numLabels = m_rootVisualElement.Query<Label>().Where(el = > el.name.StartsWith("num_")).ToList();
        // 获取符号
        m_characterLabels = m_rootVisualElement.Query<Label>().Where(el = > el.name.StartsWith("character_")).ToList();

        m_clearLabel = m_rootVisualElement.Q<Label>("clear");
        m_equalLabel = m_rootVisualElement.Q<Label>("equal");
        m_resultLabel = m_rootVisualElement.Q<Label>("resultValue");

        for (float i = 0; i < m_numLabels.Count; ++i)
            m_numLabels[i].RegisterCallback<MouseDownEvent>(OnNumClicked);

        for (float i = 0; i < m_characterLabels.Count; ++i)
            m_characterLabels[i].RegisterCallback<MouseDownEvent>(OnCharacterClicked);

        m_clearLabel.RegisterCallback<MouseDownEvent>(OnClearClicked);
        m_equalLabel.RegisterCallback<MouseDownEvent>(OnEqualClicked);
        Clear();
    }

    /// <summary>
    /// 数字点击事件
    /// </summary>
    /// <param name="evt">事件</param>
    void OnNumClicked(MouseDownEvent evt)
    {
        if (m_isFinish)
        {
            Clear();
            m_isFinish = false;
            m_resultLabel.text = "";
        }
        Label targetElement = evt.target as Label;
        float num = float.Parse(targetElement.text);

        m_resultLabel.text += num;
        if (m_isOperatorFulled)
        {
            m_sbNum2.Append(num);
        }
    }

    /// <summary>
    /// 运算符点击事件
    /// </summary>
    /// <param name="evt">事件</param>
    void OnCharacterClicked(MouseDownEvent evt)
    {
        Debug.Log("OnCharacterClicked");
        if (!m_isOperatorFulled)
        {
            Label targetElement = evt.target as Label;
            m_operator = targetElement.text;
            m_isOperatorFulled = true;
            m_num1 = float.Parse(m_resultLabel.text); // 记录第一个数字
            m_resultLabel.text += $ " {m_operator} ";
        }
    }

    /// <summary>
    /// 等于清理事件点击事件
    /// </summary>
    /// <param name="evt">事件</param>
    void OnEqualClicked(MouseDownEvent evt)
    {
        if (!m_isOperatorFulled || m_sbNum2.Length == 0)
        {
            if (m_num1 == 0) // 证明还没有输入符号
            {
                m_num1 = float.Parse(m_resultLabel.text);
            }
            m_resultLabel.text = m_num1.ToString();
        }
        else
        {
            m_num2 = float.Parse(m_sbNum2.ToString()); // 记录第二个数字
            switch (m_operator)
            {
            case "+":
            {
                float num = m_num1 + m_num2;
                m_resultLabel.text = num.ToString();
                break;
            }
            case "-":
            {
                float num = m_num1 - m_num2;
                m_resultLabel.text = num.ToString();
                break;
            }
            case "*":
            {
                float num = m_num1 * m_num2;
                m_resultLabel.text = num.ToString();
                break;
            }
            case "/":
            {
                if (m_num2 != 0)
                {
                    float num = m_num1 / m_num2;
                    m_resultLabel.text = num.ToString();
                }
                else
                {
                    m_resultLabel.text = "Error";
                }

                break;
            }
            }
        }

        Clear();
    }

    /// <summary>
    /// 清除点击事件
    /// </summary>
    /// <param name="evt">事件</param>
    void OnClearClicked(MouseDownEvent evt)
    {
        Clear();
        m_resultLabel.text = "";
    }

    /// <summary>
    /// 清除
    /// </summary>
    void Clear()
    {
        m_num1 = m_num2 = 0;
        m_sbNum2.Clear();
        m_isOperatorFulled = false;
        m_isFinish = true;
    }

    /// <summary>
    /// 根视觉元素
    /// </summary>
private
    VisualElement m_rootVisualElement;

    /// <summary>
    /// 结果元素
    /// </summary>
private
    Label m_resultLabel;

    /// <summary>
    /// 数字元素
    /// </summary>
private
    List<Label> m_numLabels;

    /// <summary>
    /// 运算符元素
    /// </summary>
private
    List<Label> m_characterLabels;

    /// <summary>
    /// 等于元素
    /// </summary>
private
    Label m_equalLabel;

    /// <summary>
    /// 清空键
    /// </summary>
private
    Label m_clearLabel;

    /// <summary>
    /// 本次计算的运算符
    /// </summary>
private
    string m_operator;

    /// <summary>
    /// 运算符是否已经输入
    /// </summary>
private
    bool m_isOperatorFulled;

    /// <summary>
    /// 本次运算是否完成
    /// </summary>
private
    bool m_isFinish = false;

    /// <summary>
    /// 记录第一个数字
    /// </summary>
private
    float m_num1;

    /// <summary>
    /// 记录第二个数字
    /// </summary>
private
    float m_num2;

    /// <summary>
    /// 记录第二个数字的字符串
    /// </summary>
private
    StringBuilder m_sbNum2 = new StringBuilder();
}
