import { createContext } from "react";

export type WebTableContext = {
  selectedRows: Map<string, boolean>;
  onSelectRow: ((id: string) => void) | null;
  onUnselectRow: ((id: string) => void) | null;
};

const defaultWebTableContext: WebTableContext = {
  selectedRows: new Map<string, boolean>(),
  onSelectRow: null,
  onUnselectRow: null,
};

export const WebTableContext = createContext(defaultWebTableContext);
