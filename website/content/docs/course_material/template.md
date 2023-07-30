---
title: "Template"
bookHidden: true
---
# Course material template

## Question 1

The question body would go here

---

## Text

Linked list can be defined as either a node structure doing nothing or one that is pointing to another linked list

## Links

See linked: [Recursion]({{< relref "template.md" >}})

## Button

{{< button relref="/" >}}Get Home{{< /button >}}
{{< button href="https://github.com/alex-shpak/hugo-book" >}}Contribute{{< /button >}}

## Columns

{{< columns >}} <!-- begin columns block -->
**Left Content**
Lorem markdownum insigne...

<---> <!-- magic separator, between columns -->

**Mid Content**
Lorem markdownum insigne...

<---> <!-- magic separator, between columns -->

**Right Content**
Lorem markdownum insigne...
{{< /columns >}}

## Expand

{{< expand >}}
## Markdown content
Lorem markdownum insigne...
{{< /expand >}}

## Hint

{{<hint warning>}}
<!-- Can do info, warning, danger -->
**Warning:** Make sure to always free up memory!
{{</hint>}}

## KaTeX

{{< katex block text-center >}}
f(x) = \int_{-\infty}^\infty\hat f(\xi)\,e^{2 \pi i \xi x}\,d\xi
{{</katex>}}

## Tabs

{{< tabs "uniqueid" >}}
{{< tab "MacOS" >}} # MacOS Content {{< /tab >}}
{{< tab "Linux" >}} # Linux Content {{< /tab >}}
{{< tab "Windows" >}} # Windows Content {{< /tab >}}
{{< /tabs >}}

---

## Code

```cpp
typedef struct node {
    struct node* nxt; // will point to the next node in the linked list if any
    int val; // store whatever else you might need
} Node;

int main() {
    // Code here
}
```

